'use strict';

var mongoose = require('mongoose');
var Test = mongoose.model('Test');
var User = mongoose.model('User');

var fs = require("fs");


var path = require('path');

//Controller functions called on by the route script
exports.home = function (req, res) {

    if (req.signedCookies.rme == 'true') {
        res.redirect('/posts')
    }
    else {
        res.render('SigninPage.ejs')
    }
};

exports.redirect_posts = function (req, res) {


    //TODO: Read (res.body) for login info
    const user = new User(req.body);
    console.log(req.body);
    user.save();

    res.cookie('user', req.body.username, { signed: true });

    //res.json(user);
    res.redirect('/posts')
};

exports.to_post = function (req, res) {

    res.render('UI.ejs');
};

exports.read_post = function (req, res) {


    //TODO: Read (res.body) for post text
    var l = new Test(req.body);
    console.log(l);

    var x = l.toJSON();


    console.log(x.name);
    console.log(req.signedCookies.user);

    var c_user = req.signedCookies.user;

    l.save();

    fs.appendFile('public/test.txt', c_user + ': ' +  x.name + '\n', function (err) {
        if (err) {
            console.log(err);
            return console.error
        };
    });


    res.render('UI.ejs');

};

exports.login = function (req, res) {

    var q = User.find({ 'username': req.body.username });

    q.exec(function (err, i) {

        if (!i.length) {
            console.log("User Not Found");

            res.redirect('/');
        }

        i.forEach(function (ii) {

            if (ii.password.length == 0) {
                console.log("User not found");
            }

            var z = ii.password.localeCompare(req.body.password);

            if (!z) {
                res.cookie('user', ii.username, { signed: true });
                console.log('logged in as ' + ii.username);

                console.log(req.body.rme);
                var rme = req.body.rme;
                if (rme) {
                    console.log('true');
                    res.cookie('rme', 'true', { signed: true });
                }
                res.redirect('/posts');
            }

            else {
                console.log("Invalid Password")
            }
        })
    })
};

exports.logout = function (req, res) {

    res.clearCookie("user");
    res.clearCookie("rme");

    res.redirect('/');
}