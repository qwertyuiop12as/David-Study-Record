function Getcustomer() {
    // dict = {
    //     id: 1,
    //     name: 'David Jaewook Cho',
    //     isGold: true,
    //     email: 'jaeugjo14@gmail.com'
    // };

    // console.log("type: ", typeof(dict));

    return {
        id: 1,
        name: 'David Jaewook Cho',
        isGold: true,
        email: 'jaeugjo14@gmail.com'
    };
}

function GetTopMovies() {
    return ['movie1', 'movie2'];
}

function SendEmail() {
    return "Email sent...";
}

const Customer = () => {
    customer = Getcustomer();

    return new Promise((resolve, reject) => {
        if (customer) {
            console.log('Customer: ', customer);

            setTimeout(() => {
                resolve(customer);
            }, 1000);
        } else {
            reject(Error("No Customer!"));
        }
    });
}

const Movie = (customer) => {
    topMovies = GetTopMovies();

    return new Promise((resolve, reject) => {
        if (topMovies) {
            if (customer.isGold)
                console.log("TopMovies:", topMovies);

            setTimeout(() => {
                resolve(customer);
            }, 1000);
        } else {
            reject(Error("No Movies!"))
        }
    })
}

const Email = (customer) => {
    SendEmail = SendEmail();

    return new Promise((resolve, reject) => {
        if (SendEmail) {
            if (customer.isGold)
                console.log("SendEmail:", SendEmail);

            setTimeout(() => {
                resolve();
            }, 1000);
        } else {
            reject(Error("No Email!"))
        }
    })
}

const P = () => {
    return Customer()
        .then((customer) => Movie(customer))
        .then((customer) => Email(customer))
        .catch((err) => console.log(`${err}`));
};

function solvePromsie(promise) {
    promise.then(() => {}).catch((err) => console.log(`${err}`));
}

solvePromsie(P());
