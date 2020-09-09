from django.contrib import admin
from .models import Place, MeasurementTemperature, MeasurementMoisture

admin.site.register(Place)
admin.site.register(MeasurementTemperature)
admin.site.register(MeasurementMoisture)
