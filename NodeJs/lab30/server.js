const {Telegraf} = require('telegraf');
const dotenv = require('dotenv');
const path = require('path');

dotenv.config({
    path: path.resolve('./', process.env.NODE_ENV + '.env')
});

const bot = new Telegraf(process.env.TELEGRAM_TOKEN);

bot.command('start', ctx => {
    console.log(ctx.from)
    bot.telegram.sendMessage(ctx.chat.id, 'hello there! Welcome to my new telegram bot.', {})
})

bot.hears(/\/echo (.+)/, async ctx => {
    const text = ctx.match[1];
    await ctx.reply(text);
});

bot.hears('/echo', (ctx) => {
    bot.telegram.sendMessage(ctx.chat.id, ctx.message.text);
})

bot.launch();
// Enable graceful stop
process.once('SIGINT', () => bot.stop('SIGINT'))
process.once('SIGTERM', () => bot.stop('SIGTERM'))
