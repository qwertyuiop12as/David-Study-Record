from django.urls import path
from . import views # import views.py file


urlpatterns = [
    path("", views.index), # /challenges/
    path("<int:month>", views.monthly_challenge_by_number),
    path("<str:month>", views.monthly_challenge, name="month-challenge")
    # <month> is identifier that used for parameters in view.py monthly_challenge function
]