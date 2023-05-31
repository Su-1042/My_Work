from flask import Flask, jsonify, request, g
import sqlite3
from flask_cors import CORS

app = Flask(__name__)
CORS(app)

@app.route('/add_to_playlist', methods=['POST'])
def add_to_playlist():
    song_id = request.json["song_id"]
    song_name = request.json["song_name"]
    alb_name = request.json["alb_name"]
    art_name = request.json["art_name"]

    conn = sqlite3.connect('playtable.db')
    cur = conn.cursor()
    cur.execute('CREATE TABLE IF NOT EXISTS playtable (song_id INTEGER PRIMARY KEY, song_name TEXT, alb_name TEXT, art_name TEXT);')
    cur.execute('SELECT * FROM playtable WHERE song_id = ?', (int(song_id),))
    if cur.fetchone() is not None:
        # Song already exists, do not add again
        conn.close()
        return jsonify({'status': 'error'})

    # Song does not exist, add to playlist
    cur.execute('INSERT INTO playtable (song_id, song_name, alb_name, art_name) VALUES (?, ?, ?, ?)', (int(song_id), song_name, alb_name, art_name))
    conn.commit()
    conn.close()
    return jsonify({'status': 'success'})

app.config['DATABASE'] = 'playtable.db'

def get_db():
    """Connect to the database"""
    db = getattr(g, '_database', None)
    if db is None:
        db = g._database = sqlite3.connect(app.config['DATABASE'])
        db.row_factory = sqlite3.Row
    return db

@app.teardown_appcontext
def close_db(error):
    """Close the database connection"""
    db = getattr(g, '_database', None)
    if db is not None:
        db.close()

@app.route('/app/songs', methods=['GET'])
def get_songs():
    """Retrieve all songs in the playlist"""
    db = get_db()
    songs = db.execute('SELECT * FROM playtable').fetchall()
    songs_list = [dict(song) for song in songs]
    return jsonify(songs_list)

@app.route('/', methods=['GET', 'POST'])
def playlist():
    """Display the playlist and handle song removal"""
    if request.method == 'POST':
        song_id = request.form.get('song_id')
        db = get_db()
        db.execute('DELETE FROM playtable WHERE song_id = ?', (song_id,))
        db.commit()
        return 'Song removed'
    else:
        db = get_db()
        songs = db.execute('SELECT * FROM playtable').fetchall()
        response = []
        for song in songs:
            response.append({
                'song_id': song['song_id'],
                'song_name': song['song_name'],
                'alb_name': song['alb_name'],
                'art_name': song['art_name']
            })
    return jsonify(response)


if __name__ == '__main__':
    app.run(port = 8000,debug=True)
