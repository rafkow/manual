python manage.py shell

python manage.py shell < relations_test.py

from sheerjoy.models import Gallery

g = list(Gallery.objects.all())
g[0].get_hashtags()
