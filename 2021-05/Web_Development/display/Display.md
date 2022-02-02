# Display

```display```는 요소를 어떻게 화면상에 나타낼 것인지를 정해준다

![img](https://cdn-images-1.medium.com/max/800/1*UHFIA8O-CK97x4Uhpt4szg.png)

![img](https://cdn-images-1.medium.com/max/800/1*zidHqHn01gjt8NTwxwNBJw.png)

## block

```html
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <link rel="stylesheet" href="./block.css" />
    <title>display</title>
  </head>
  <body>
    <div>11</div>
    <div>2</div>
    <div>3</div>
    <div>4</div>
    <div>5</div>
  </body>
</html>
```



```css
div {
  background-color: red;
  height: 100%;

  width: 100px;

  font-size: 50px;
  color: white;
}
```

해당 html의 코드 구성을 보자면

- `body` 태그
- 숫자를 text로 가지는 `div` 태그 5개



css의 style까지 적용 한다면 해당 html 코드는 







![img](https://cdn-images-1.medium.com/max/800/1*UHFIA8O-CK97x4Uhpt4szg.png)

이런 모양으로 나온다





```css
div {
  display: block;
  /* display에 아무것도 지정하지 않는다면 자동으로 display는 block이 된다. */
  
    
  background-color: red;
  height: 100%;

  width: 100px;

  font-size: 50px;
  color: white;
}
```



- **기본 값으로 `display`에는 `block`이 적용된다.**
- display : block은 각 요소들을 **블럭처럼 쌓은 느낌.**
- **한줄에 한개의 요소만 담는다.**
- **요소가 width를 가질 수 있다.**



```css
div {
  display: block;
  /* display에 아무것도 지정하지 않는다면 자동으로 display는 block이 된다. */
  
    
  background-color: red;
  height: 100%;

  width: 300px;

  font-size: 50px;
  color: white;
}
```



요소가 width를 가질 수 있으므로 **width 값을 300으로 바꾸면 실제로 적용이 된다.**

![img](https://cdn-images-1.medium.com/max/800/1*J-ZW0WiFr3LgQlBOOsPxwg.png)

## inline

```html
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <link rel="stylesheet" href="./block.css" />
    <title>display</title>
  </head>
  <body>
    <div>11</div>
    <div>2</div>
    <div>3</div>
    <div>4</div>
    <div>5</div>
  </body>
</html>
```

```css
div {
  display: inline;

  background-color: red;
  height: 100%;
  
  width: 200px;
  /* width에 200px를 줘도 한 줄에 최대한 많은 요소를 담기 위해서 text크기에 맞게 width가 적용됨 */
  /* 따라서 inline에서는 width를 줘도 의미가 없다. */

  font-size: 50px;
  color: white;
}
```



![img](https://cdn-images-1.medium.com/max/800/1*oFE0dbCPdDCwMjxhrd7UBA.png)

- **inline은 한줄에 최대한 많은 요소를 담는다.**
- 한줄에 요소를 담기 때문에 **요소마다 width를 <u>줄 수가 없다</u>.**
- 요소가 너무 많아지면 다음줄로 넘어가진다.

![img](https://cdn-images-1.medium.com/max/800/1*sfQm3aWlDN9aAEPgEsa3fg.png)

## inline-block

```html
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <link rel="stylesheet" href="./block.css" />
    <title>display</title>
  </head>
  <body>
    <div>11</div>
    <div>2</div>
    <div>3</div>
    <div>4</div>
    <div>5</div>
  </body>
</html>
```

```css
div {
  display: inline-block;

  background-color: red;
  height: 100%;

  width: 100px;
  /* inline-block의 경우 inline처럼 한줄에 여러 요소를 담을 수도 있고 block처럼 width를 주어 길이를 지정할 수도 있다 */
  font-size: 50px;
  color: white;
}
```

![img](https://cdn-images-1.medium.com/max/800/1*eBSoNnBXHyISoI9SBBWI5g.png)

- ``inline-block``의 경우 ``inline``처럼 한줄에 여러 요소를 담을 수도 있고 ``block``처럼 width를 주어 길이를 지정할 수도 있다.
- **한줄에 요소들을 넣으면서 width까지 적용하려고 할 때 사용한다.**



```html
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>inline_block</title>
    <style>
      section {
        border: 10px solid red;
        font-size: 5rem;
        text-align: center;
        /* text-align의 방향을 left, right로 바꾸어서 실제로 정렬 방향이 div에도 적용 되는지 확인이 가능 */
      }

      section > div {
        width: 100px;
        height: 100px;
        background-color: green;
        display: inline-block;
        /* div요소 하나하나가 글자처럼 취급됨 */
        /* 따라서  section tag의 "text-align: center"는 div를 글자처럼 봐서 div도 정렬을 해줌*/
      }
    </style>
  </head>
  <body>
    <section>
      1234
      <div></div>
      <div></div>
      <div></div>
      <div></div>
      <div></div>
    </section>
  </body>
</html>
```

![img](https://cdn-images-1.medium.com/max/800/1*9sG1AoPvnDnkZbyBRhPb1A.png)

- ```inline-block```은 요소를 문자처럼 취급하기도 한다.
- 따라서 ```text-align```을 사용했음에도 불구하고 ```div``` 태그들 조차 정렬된 것을 확인할 수 있다.