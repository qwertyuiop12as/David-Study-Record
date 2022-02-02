from django.shortcuts import render
from django.http import HttpResponse, HttpResponseNotFound, HttpResponseRedirect
from django.urls import reverse

monthly_challenges = {
    "january": "Happy January!",
    "february": "Happy February!",
    "march": "Happy March!",
    "april": "Happy April!",
    "may": "Happy May!",
    "june": "Happy June!",
    "july": "Happy July!",
    "august" : "Happy August!",
    "september" : "Happy September!",
    "october" : "Happy October!",
    "november" : "Happy November!",
    "december" : "Happy December!"
}
# Create your views here.

def index(request, month):
    return HttpResponse("This works!")

def home(request) :
    months = list(monthly_challenges.keys())
    list_items = ""

    for month in months :
        capitalized_month = month.capitalize()
        month_path = reverse("month-challenge", args=[month])
        list_items += f"<li><a href=\"{month_path}\" target = \"_blank\">{capitalized_month}</a></li>\n"
    
    response_data = f"<ul>{list_items}</ul>"
    return HttpResponse(response_data)


def monthly_challenge_by_number(request, month):
    months = list(monthly_challenges.keys())

    if month > len(months):
        return HttpResponseNotFound("Invalid month")

    month_by_char = months[month-1]
    redirect_path = reverse("month-challenge", args=[month_by_char])
    # urls.py에 있는 name = "month-challenge"와 연결 시켜 /challenge를 만들고 인자값으로 month_by_char을 넣는다

    return HttpResponseRedirect(redirect_path)

def monthly_challenge(request, month):
    try: 
        challenge_text = monthly_challenges[month]
        response_data = f"<h1>{challenge_text}</h1>"
        return HttpResponse(response_data)
    except:
        return HttpResponseNotFound("<h1>This month is not supported!</h1>")
        