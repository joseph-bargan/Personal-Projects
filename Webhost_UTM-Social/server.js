'use strict';
var express = require('express');
var port = process.env.PORT || 3000;
const app = express();
const cookierParser = require('cookie-parser')
var bodyParser = require("body-parser");
var methodOverride = require('method-override');
var session = require('express-session');
var path = require('path');

var mongoose = require('mongoose');

//Configurations
app.set('views', './app/views');
app.set('view engine', 'ejs');
app.use(express.static(__dirname + '/public'));

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));
app.use(methodOverride());
app.use(cookierParser('abcdef-12345'))

app.use(session({
    saveUnintialized: true,
    resave: true,
    secret: 'sesSecret'
}))

app.locals.mongoose = mongoose;

const configMongoose = require('./config/mongoose');
const db = configMongoose();


var routes = require('./app/routes/TestRoute'); //importing routes
routes(app); //telling app the use these routes




app.listen(port);
console.log('working');

