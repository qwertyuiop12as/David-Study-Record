from django import forms

class ReviewForm(forms.Form):
    user_name = forms.CharField(label="Your Name", required = True, min_length=2, max_length=100, error_messages = {
        "required": "Your name must not be empty",
        "max_length": "Please enter a shorter name!",
        "min_length": "Please enter a longer name!"
    })