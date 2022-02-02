# box-sizing

#### **box-sizing type**

``border-box`` ``content-box`` ```auto```

- ``border-box`` : content에 추가적으로 길이를 늘릴 때(border, padding) **전체 길이를 고정시킨 채** 더해준다.                                                                                                                                                (전체 길이가 안 바뀜, 원래 있던 애가 작아짐) 

- ``content-box`` : content에 추가적으로 길이를 늘릴 때 **전체 길이를 늘려가면서** 더해준다.           (전체 길이가 바뀜) 

  

- 따로 특별한 설정을 안해주면 **box-sizing**에서는 ``content-box``가 기본 값으로 적용됨.

![img](https://cdn-images-1.medium.com/max/800/1*OVUID-QlJraPrExW4G6H1w.png)



<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        .container{
            width : 300px;
            border: 5px solid gold;
            background-color: rgb(255, 123, 0);
        }


```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        .border_box {
            width : 300px;
            border: 5px solid gold;
            background-color: rgb(255, 123, 0);
        }

        .border_box > div {
            width : 100%;
            padding: 20px;
            border: 3px solid purple;
            margin-bottom : 20px;
        }

        .border_box .content1 {
            background-color: red;
            /* box-sizing: content-box; 
               아무 것도 안 쓰면 content-box가 기본 설정*/
        }

        .border_box .content2 {
            background-color: blue;
            box-sizing: border-box;
        }
    </style>
</head>
<body>
    <div class = "border_box">
        <div class = "content1"></div>
        <div class = "content2"></div>
    </div>
</body>
</html>
```



- ```auto``` : **기존 content의 길이를 줄여가면서** 자동으로 사이즈를 맞춰줌. 부모 요소의 content 길이는 넘길 수 없다.
- **부모 content의 최소 길이**(아무것도 없으면 0)이 될 때까지 줄인다.
- 따로 width를 지정해주지 않으면 **자동으로  ```auto```**가 된다.

![img](https://cdn-images-1.medium.com/max/800/1*oXRp5tCSoYLP9F3qn6JG1A.png)

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        .container{
            width : 300px;
            border: 5px solid gold;
            background-color: rgb(255, 123, 0);
        }

        .container > div {
            padding: 20px;
            border: 3px solid purple;
            margin-bottom : 20px;
        }

        .container .child1 {
            width : 100%;
            background-color: aqua;
            /* box-sizing: content-box; 
            아무것도 안 쓰면 content-box가 기본 설정*/
        }

        .container .child2 {
            width : 100%;
            background-color: red;
            box-sizing: border-box;
        }

        .container .child3 {
            width: auto;
            background-color: greenyellow;
        }

        .container .child4 {
            /* width : auto;
            아무것도 안 쓰면 auto가 기본 설정 */
            background-color: black;
        }
        
    </style>
</head>
<body>
    <div class = "container">
        <div class = "child1"></div>
        <div class = "child2"></div>
        <div class = "child3"></div>
        <div class = "child4"></div>
    </div>
</body>
</html>
```

