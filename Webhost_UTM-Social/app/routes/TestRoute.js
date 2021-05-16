'use strict';
module.exports = function (app) {
    const index = require("../controllers/TestController");

    //Url routes

    app.get('/', index.home);

    app.post('/', index.redirect_posts);

    app.post('/login', index.login);

    app.get('/logout', index.logout);

    app.get('/posts', index.to_post);

    app.post('/posts', index.read_post);
        
};
