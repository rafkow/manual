# add models in admin panel in file admin.py
admin.site.register(Place)
admin.site.register(MeasurementTemperature)
admin.site.register(MeasurementMoisture)


class Place(models.Model):
    name = models.CharField(max_length=30, default="description")


class MeasurementTemp(models.Model):
    date = models.DateTimeField(auto_now_add=True)  # permanentnie wstawia aktualną date
    date = models.DateTimeField(default=datetime.now())  # jeśli nie ma podanej daty wstawia aktualna
    value = models.SmallIntegerField()
    place = models.ForeignKey(Place, on_delete=models.CASCADE)
