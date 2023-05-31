import json
from flask import Flask,render_template, request, redirect, url_for
app = Flask(__name__)


@app.route('/')
def index():
    return render_template("formpage.html")


@app.route('/register', methods=['POST','GET'])
def register():
    name = request.form['name']
    email = request.form['email']
    password = request.form['password']

    # Append the user's data to users.txt
    user_data = {'name': name, 'email': email, 'password': password}
    with open('users.txt', 'a') as f:
        f.write(json.dumps(user_data) + '\n')

    # Display the registration details of the user
    return redirect(url_for('user_details', email=email))


@app.route('/users/<email>')
def user_details(email):
    with open('users.txt', 'r') as f:
        for line in f:
            user_data = json.loads(line)
            if user_data['email'] == email:
                return 'Name: {}, Email: {}, Password: {}'.format(user_data['name'], user_data['email'], user_data['password'])
    return 'User not found'


@app.route('/users')
def all_users():
    users = []
    with open('users.txt', 'r') as f:
        for line in f:
            line = line.strip()  
            if line:   
                user_data = json.loads(line)
                users.append(user_data)


    #json.dumps() used to convert users into a json formatted string
    return json.dumps(users)


if __name__ == '__main__':
    app.run(debug=True)
