from flask import Flask
import time

app = Flask(__name__)


@app.route("/<message>")
def echo(message):
    return message


if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')



@app.route('/lucky')
def lucky():
	def GetLuckyNumber():
		while True:
			yield('data: 50')
			time.sleep(1.0)
	return Response(GetLuckyNumber(), mimetype='text/event-stream')

@app.route('/', methods=['GET', 'POST'])
def index():
    return render_template('main.html')


from flask import Flask
app = Flask(__name__)

@app.route("/")
def hello():
    return "<h1 style='color:blue'>Hello Marsboard</h1>"

@app.route("/<message>")
def echo(message):
    return message

if __name__ == "__main__":
    app.run(host='0.0.0.0')
