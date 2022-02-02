from django.http.response import HttpResponseRedirect
import challenges
from django.shortcuts import render
from django.http import HttpResponse, HttpResponseNotFound, HttpResponseRedirect
from django.urls import reverse

# Create your views here.

monthly_challenges = {
    "january" : "Happy January",
    "february" : "Happy February",
    "march" : "Happy March",
    "april" : "Happy April",
    "may" : "Happy May",
    "june" : "Happy June",
    "july" : "Happy July",
    "august" : "Happy August",
    "september" : "Happy September",
    "october" : "Happy October",
    "november" : "Happy November",
    "december" : "Happy December"
}

def index(request):
    list_items = ""
    months = list(monthly_challenges.keys())

    for month in months :
        capitalized_month = month.capitalize()
        month_path = reverse("month-challenge", args=[month])
        list_items += f"<li><a href=\"{month_path}\">{capitalized_month}</a></li>"




    response_data = f"<ul>{list_items}</ul>"
    return HttpResponse(response_data)


def monthly_challenge_by_number(request, month) :
    months = list(monthly_challenges.keys())

    if month > len(months) :
        return HttpResponseNotFound("Invalid month")

    redirect_month = months[month - 1]
    redirect_path = reverse("month-challenge", args=[redirect_month]) # /challenge/january
    return HttpResponseRedirect(redirect_path)


def monthly_challenge(request, month):
    try:
        return_value = monthly_challenges[month]
        response_data = f"<h1>{return_value}</h1>"
        return HttpResponse(response_data)
    except:
        return HttpResponseNotFound("<h1>This month is not supported</h1>")
