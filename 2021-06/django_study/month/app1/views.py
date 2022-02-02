from django.shortcuts import render
from django.http import HttpResponse

# Create your views here.
def get_month(request, month) :
    return HttpResponse(month)
