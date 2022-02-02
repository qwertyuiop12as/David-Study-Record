from django.shortcuts import render
from django.http import HttpResponse, HttpResponseNotFound, HttpResponseRedirect, response, Http404
from django.urls import reverse
from django.template.loader import render_to_string

monthly_challenges = {
    "january" : "happy january",
    "february" : "happy february",
    "march" : "happy march",
    "april" : "happy april",
    "may" : "happy may",
    "june" : "happy june",
    "july" : "happy july",
    "august" : "happy august",
    "september" : "happy september",
    "october" : "happy october",
    "november" : "happy november",
    "december" : None
}

# Create your views here.

# def index(request):
#     print('request', request)
#     return HttpResponse("This works!")

# def january(request) :
#     return HttpResponse("Happy New Year!")

# def february(request) :
#     return HttpResponse("Happy February!")

# def march(request):
#     return HttpResponse("MMMMMMMMM")

def index(request) :
    list_items = ""
    months = list(monthly_challenges.keys())

    for month in months:
        capitalized_month = month.capitalize()
        month_path = reverse("month-challenge", args=[month])
        list_items += f"<li><a href=\"{month_path}\">{capitalized_month}</a></li>"

    # response_data = """
    #     <ul>
    #         <li><a href="/challenges/january">January</a></li>
    #     </ul>
    # """
    response_data = f"<ul>{list_items}</ul>"
    return HttpResponse(response_data)


def index(request) :
    list_items = ""
    months = list(monthly_challenges.keys())

    return render(request, "challenges/index.html", {
        "months": months
    })

# return int numbers that we got by input
def monthly_challenge_by_number(request, month):
    # return list of keys
    months = list(monthly_challenges.keys())

    if month > len(months):
        return HttpResponseNotFound("Invalid month")

    # subtract 1 because list index starts with 0
    redirect_month = months[month - 1]
    # return HttpResponseRedirect("/challenge/" + redirect_month)

    redirect_path = reverse("month-challenge", args=[redirect_month]) # /challenge/january
    return HttpResponseRedirect(redirect_path)

# def monthly_challenge(request, month):
#     challenge_text = None
#     if month == 'january':
#         challenge_text = "happy january"
#     elif month == 'february':
#         challenge_text = "happy february"
#     elif month == 'march':
#         challenge_text = "happy march"

      # ------------- if there is no matched value with input, we print error ----------------
#     else:
#         return HttpResponseNotFound("This month is not supported!")

#     return HttpResponse(challenge_text)


# dynamic
# by key & value in dictionary
def monthly_challenge(request, month):
    try:
        # print("AAAA")
        # print(month)
        challenge_text = monthly_challenges[month]
        # response_data = render_to_string("challenges/challenge.html")
        # return HttpResponse(response_data)
        return render(request, "challenges/challenge.html", {
            "text": challenge_text,
            "month_name": month
        })
    except:
        print(month)
        response_data = render_to_string("404.html")
        return HttpResponseNotFound(response_data)
        # raise Http404()