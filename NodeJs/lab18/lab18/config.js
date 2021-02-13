config ={
    username: 'Vad',
    password: 'Vad',
    database: 'GVA',
    host: 'localhost',
    dialect: 'mssql',
    logging: false,
    enableArithAbort: true,
    trustServerCertificate: true,
    define: {
        hooks: {
            beforeCreate(attributes, options) {
                console.log("before create all");
            },
            afterCreate(attributes, options) {
                console.log("after create all");
            }
        }
    },
    pool: {
        max: 5,
        min: 0,
        idle: 10000
    }
}

exports.config = config;