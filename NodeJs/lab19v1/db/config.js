config = {
    username: 'Arcuman',
    password: 'QWEaz45@',
    database: 'Store',
    host: 'localhost',
    dialect: 'mssql',
    logging: false,
    enableArithAbort: true,
    trustServerCertificate: true,
    pool: {
        max: 5,
        min: 0,
        idle: 10000
    }
}

exports.config = config;