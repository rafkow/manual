from django.urls import path, include

from app.api.views import api_details_measurement

app_name = 'app'

urlpatterns = [
    path('api/', include('api.urls')),
    # pelna scieżka dla zagnieżdżonych i app_name jako 2 parametr include
    path('api/', include('app.api.urls', 'api')),

]
