//loading mongoose dependencies
const mongoose = require('mongoose');

module.exports = function () {
    const db = mongoose.connect('mongodb://localhost/text-db');

    require('../app/models/TestModel');

    return db;
}