from django.shortcuts import render
from django.http import HttpResponse, HttpResponseNotFound

def test_def(request, number) :
    output_num = number
    return HttpResponse(f"<h1>{output_num}</h1>")