'use strict';

var mongoose = require('mongoose');
var schema = mongoose.Schema;

//Sample model-schema to be stored in databse
var Test = new schema({

    name: {
        type: String,
    }

});

Test.set('toJSON', {
    getters: true,
    virtuals: true
});

const User = new schema({

    

    email: String,
    username: String,
    password: String,
});

User.set('toJSON', {
    getters: true,
    virtuals: true
});


Test.set('toJSON', {
    getters: true,
    virtuals: true
});



mongoose.model('User', User);
mongoose.model('Test', Test);