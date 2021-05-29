const TelegramBot = require('node-telegram-bot-api')
const dotenv = require('dotenv');
const path = require('path');

dotenv.config({
    path: path.resolve('./', process.env.NODE_ENV + '.env')
});

const token = process.env.TELEGRAM_TOKEN;


let users = []
const bot = new TelegramBot(token, { polling: true })

bot.onText(/\/echo (.+)/, (msg, match) => {
    const chatId = msg.chat.id
    const resp = match[1]

    bot.sendMessage(chatId, resp)
})

bot.on('message', (msg) => {
    const chatId = msg.chat.id
    if (msg.text === 'dog') {
        bot.sendMessage(chatId, "You sent 'dog'")
    }
})

bot.onText(/\/register/, (msg, match) => {
    const chatId = msg.chat.id
    users.push(chatId)
    console.log('user registered')
    bot.sendMessage(chatId, 'Done.')
})

setInterval(function () {
    if (users.length > 0) {
        for (let i = 0; i < users.length; i++) {
            bot.sendMessage(users[i], 'Is this annoying?')
        }
    } else {
        console.log('no user registered')
    }
}, 3000)
