from datetime import date

from django.shortcuts import get_object_or_404, render

from .models import Post

def get_date(post) :
    return post['date']

def starting_page(request):
    latest_posts = Post.objects.all().order_by("-date")[:3]
    return render(request, "blog/index.html", {
        "posts": latest_posts
    })


# all_posts = [
#     {
#         "slug": "hike-in-the-mountains",
#         "image": "mountains.jpg",
#         "author": "David Cho",
#         "date": date(2021, 6, 24),
#         "title": "Mountain Hiking",
#         "excerpt": "There's nothing like the views you get when hiking in the mountains! And I wasn't even prepared for what happened whilst I was enjoying the view",
#         "content": """
#             Lorem ipsum dolor sit, amet consectetur adipisicing elit. Excepturi officiis
#             ex est doloremque earum minus, molestias ea labore suscipit tempore optio?
#             Neque suscipit eum ab totam tempora possimus corrupti molestias?
            
#             Lorem ipsum dolor sit, amet consectetur adipisicing elit. Excepturi officiis
#             ex est doloremque earum minus, molestias ea labore suscipit tempore optio?
#             Neque suscipit eum ab totam tempora possimus corrupti molestias?
            
#             Lorem ipsum dolor sit, amet consectetur adipisicing elit. Excepturi officiis
#             ex est doloremque earum minus, molestias ea labore suscipit tempore optio?
#             Neque suscipit eum ab totam tempora possimus corrupti molestias?
#         """
#     },
#     {
#         "slug": "hike-in-the-mountains",
#         "image": "coding.jpg",
#         "author": "David Cho",
#         "date": date(2021, 6, 24),
#         "title": "Mountain Hiking",
#         "excerpt": "There's nothing like the views you get when hiking in the mountains! And I wasn't even prepared for what happened whilst I was enjoying the view",
#         "content": """
#             Lorem ipsum dolor sit, amet consectetur adipisicing elit. Excepturi officiis
#             ex est doloremque earum minus, molestias ea labore suscipit tempore optio?
#             Neque suscipit eum ab totam tempora possimus corrupti molestias?
            
#             Lorem ipsum dolor sit, amet consectetur adipisicing elit. Excepturi officiis
#             ex est doloremque earum minus, molestias ea labore suscipit tempore optio?
#             Neque suscipit eum ab totam tempora possimus corrupti molestias?
            
#             Lorem ipsum dolor sit, amet consectetur adipisicing elit. Excepturi officiis
#             ex est doloremque earum minus, molestias ea labore suscipit tempore optio?
#             Neque suscipit eum ab totam tempora possimus corrupti molestias?
#         """
#     },
#     {
#         "slug": "hike-in-the-mountains",
#         "image": "woods.jpg",
#         "author": "David Cho",
#         "date": date(2021, 6, 24),
#         "title": "Mountain Hiking",
#         "excerpt": "There's nothing like the views you get when hiking in the mountains! And I wasn't even prepared for what happened whilst I was enjoying the view",
#         "content": """
#             Lorem ipsum dolor sit, amet consectetur adipisicing elit. Excepturi officiis
#             ex est doloremque earum minus, molestias ea labore suscipit tempore optio?
#             Neque suscipit eum ab totam tempora possimus corrupti molestias?
            
#             Lorem ipsum dolor sit, amet consectetur adipisicing elit. Excepturi officiis
#             ex est doloremque earum minus, molestias ea labore suscipit tempore optio?
#             Neque suscipit eum ab totam tempora possimus corrupti molestias?
            
#             Lorem ipsum dolor sit, amet consectetur adipisicing elit. Excepturi officiis
#             ex est doloremque earum minus, molestias ea labore suscipit tempore optio?
#             Neque suscipit eum ab totam tempora possimus corrupti molestias?
#         """
#     }
# ]

# def get_data(post) :
#     return post["date"]

# # Create your views here.

# def starting_page(request):
#     sorted_posts = sorted(all_posts, key=get_data)
#     latest_posts = sorted_posts[-3:]
#     return render(request, "blog/index.html", {
#         "posts": latest_posts
#     })

def posts(request):
    all_posts = Post.objects.all().order_by("-date")
    return render(request, "blog/all-posts.html", {
        "all_posts": all_posts
    })

def post_detail(request, slug):
    identified_post = get_object_or_404(Post, slug=slug)
    return render(request, "blog/post-detail.html", {
        "post": identified_post,
        "post_tags": identified_post.tags.all()
    })