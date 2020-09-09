from flask import *
import random_number
import time

app = Flask(__name__)

@app.route('/', methods=['GET', 'POST'])
def index():
    return render_template('main.html')

@app.route('/lucky')
def lucky():
	def GetLuckyNumber():
		while True:
			yield('data: 50')
			time.sleep(1.0)
	return Response(GetLuckyNumber(), mimetype='text/event-stream')
	

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')