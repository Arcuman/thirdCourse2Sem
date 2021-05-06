const config = {
  env: process.env.NODE_ENV || 'development',
  port: process.env.PORT || 3000,
  jwtSecret: process.env.JWT_SECRET || "Qswed34SDa",
  mongoUri: process.env.MONGODB_URI ||
    process.env.MONGO_HOST ||
    'mongodb://' + (process.env.IP || 'localhost') + ':' +
    (process.env.MONGO_PORT || '27017') +
    '/mernproject',
  stripe_connect_test_client_id: 'ca_JH9m6BGljB8gFLFE7CCeFmBJyCkQ9ul9',
  stripe_test_secret_key: 'sk_test_51IebKKIovhq8edAWWUv6LBdauZnp0wwfCqodKNRELTqw2OgWMI4DEWLHdc8ZfoCjdpK99nHpas9DoYtU6yTy95lL00RsiGlqqt',
  stripe_test_api_key: 'pk_test_51IebKKIovhq8edAWUF4fc3KdyHHIfgYLw5XzSSigN1GcRSGAfokojYcuZhYFx3El6mhd4jS9LufoKGzMooJwu7tC00KbXQN08U'
}

export default config
