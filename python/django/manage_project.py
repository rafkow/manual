Start project:
	django-admin startproject mysite

Create app:
	python manage.py startapp mysiteapp

Run server:
	python manage.py runserver [0:8000] # interface:port

Create superuser
	python manage.py createsuperuser

After edit admin.py
	python manage.py migrate
	python manage.py makemigrations [name_app]
	python manage.py migrate


config(
        'DB_CONNECTION_SETTINGS',
        default=f'sqlite:///db.sqlite3',
        cast=db_url
)