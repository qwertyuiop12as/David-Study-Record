from django.core import validators
from django.db import models
from django.core.validators import MinValueValidator, MaxValueValidator
from django.urls import reverse
from django.utils.text import slugify

# Create your models here.


class Country(models.Model):
    name = models.CharField(max_length=80)
    code = models.CharField(max_length=2)

    def __str__(self):
        return self.name

    class Meta:
        verbose_name_plural = "Countries"


class Address(models.Model):
    street = models.CharField(max_length=80)
    postal_code = models.CharField(max_length=5)
    city = models.CharField(max_length=50)


class Author(models.Model):
    first_name = models.CharField(max_length=100)
    last_name = models.CharField(max_length=100)
    address = models.OneToOneField(
        Address, on_delete=models.CASCADE, null=True)

    def full_name(self):
        return f"{self.first_name} {self.last_name}"

    def __str__(self):
        return self.full_name()


class Book(models.Model):
    title = models.CharField(max_length=50)
    rating = models.IntegerField(
        validators=[MinValueValidator(1), MaxValueValidator(5)])

    # related_name은 얘가 참조하는 애를 찾을 때 쓰는 이름
    author = models.ForeignKey(
        Author, on_delete=models.CASCADE, null=True, related_name="books")
    is_bestselling = models.BooleanField(default=False)

    # Harry Potter 1 => harry-potter-1
    slug = models.SlugField(default="", blank=True, null=False, db_index=True)
    # editable=False,
    published_countries = models.ManyToManyField(Country, related_name="books")

    def get_absolute_url(self):
        return reverse("book-detail", args=[self.slug])

    # def save(self, *args, **kwargs):
    #     self.slug = slugify(self.title)
    #     super().save(*args, **kwargs)

    # ***** Adding the Slugfield & Overwriting Save *****
    # from book_outlet.models import Book

    # Book.objects.get(title="Harry Potter 1").save()
    # Book.objects.get(title="Harry Potter 1").slug

    def __str__(self):
        return f"{self.title} ({self.rating})"


# python manage.py makemigrations
# python manage.py migrate

# from book_outlet.models import Book
# Book.objects.all()
# Book.objects.all()[1].author
# Book.objects.all()[1].is_bestselling

# harry_potter = Book.objects.all()[0]
# harry_potter.title
# harry_potter.author = "J.K. Rowling"
# harry_potter.is_bestselling = True
# harry_potter.save()

# harry_potter.delete()

# Book.objects.create(title="Harry Potter 1", rating=5, author="J.K. Rowling", is_bestselling=True)
# Book.objects.create(title="My Story", rating=1, author="Me Myself", is_bestselling=False)


# ***** Querying & Filtering Data *****

# Book.objects.get(is_bestselling=True)
# Book.objects.filter(is_bestselling=True)
# Book.objects.filter(rating__lte=3, title__icontains="Story")
# from django.db.models import Q
# Book.objects.filter(Q(rating__lt=3) | Q(is_bestselling=True))
# Book.objects.filter(Q(rating__lt=3) | Q(is_bestselling=True), Q(author="J.K. Rowling"))
# Book.objects.filter(Q(author="J.K. Rowling"), Q(rating__lt=3) | Q(is_bestselling=True))


# cashing

# bestsellers = Book.objects.filter(is_bestselling=True)
# amazing_bestsellers = bestsellers.filter(rating__gt=4)
# print(bestsellers)
# print(amazing_bestsellers)


# You can delete multiple model instances(i.e. database records) at once
# You can update multiple model instances(i.e. database records) at once
# You can create multiple model instances(i.e. database records) at once
