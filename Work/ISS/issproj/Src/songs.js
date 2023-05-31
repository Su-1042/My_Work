function addToPlaylist(songId, songName, albumName, artistName) {
    const data = {
        song_id: songId,
        song_name: songName,
        alb_name: albumName,
        art_name: artistName
    };

    fetch('http://127.0.0.1:8000/add_to_playlist', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify(data)
    })
    .then(response => response.json())
    .then(data => {
        if (data.status === 'success') {
            alert('Song added to playlist successfully!');
        } else {
            alert('Error: Could not add song to playlist.');
        }
    })
    .catch(error => {
        console.error('Error:', error);
        alert('Error: Could not add song to playlist.');
    });
}
