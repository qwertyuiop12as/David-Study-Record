GetCustomer(1, (customer) => {
    console.log('Customer: ', customer);
    if (customer.isGold) {
        GetTopMovies((movies) => {
            console.log('Top movies: ', movies);
            SendEmail(customer.email, movies, () => {
                console.log('Email sent...')
            });
        });
    }
});

function GetCustomer(id, callback) {
    setTimeout(() => {
        callback({
            id: 1,
            name: 'David Jaewook Cho',
            isGold: false,
            email: 'jaeugjo14@gmail.com'
        });
    }, 4000);
}

function GetTopMovies(callback) {
    setTimeout(() => {
        callback(['movie1', 'movie2']);
    }, 4000);
}

function SendEmail(email, movies, callback) {
    setTimeout(() => {
        callback();
    }, 4000);
}

