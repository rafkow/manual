# settings.py
MEDIA_ROOT = os.path.join(BASE_DIR, 'media')
MEDIA_URL = '/media/'

# models
image = models.ImageField(upload_to='gallery/')

# urls.py
# zbadaj co to takiego
if settings.DEBUG:
    urlpatterns += static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)

# template
<a href="{{ photo.image.url }}">
