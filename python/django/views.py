from django.shortcuts import render
from django.views.generic import View, TemplateView
from django.http.response import HttpResponse



def index(request):
    return render(request, 'index.html')

class AppView(View):
    def get(self, request):
        return HttpResponse('Your library is cool!')

class IndexView(TemplateView):
    template_name = 'index.html'

    def get_context_data(self, **kwargs):
        context = super().get_context_data(**kwargs)
        context['inject'] = 'you are great!'
        return context


    if request.method == 'GET':
        try:
            measurements = MeasurementTemperature.objects.all()
            serializer = TemperatureSerializer(measurements, many=True)
            return JsonResponse(serializer.data, safe=False)
        except MeasurementTemperature.DoesNotExist:
            return Response(status=status.HTTP_404_NOT_FOUND)

    elif request.method == 'POST':
        data = JSONParser().parse(request)
        serializer = TemperatureSerializer(data=data)
        if serializer.is_valid():
            serializer.save()
            return JsonResponse(serializer.data, status=201)
        return JsonResponse(serializer.errors, status=400)
