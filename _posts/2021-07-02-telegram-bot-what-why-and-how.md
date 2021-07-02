---
layout: post
title:  "TELEGRAM BOT: WHAT, WHY AND HOW"
date:   2021-07-02 17:12:59 +0700
author: "Akhmal R"
categories: english article
---

# Telegram Bot: Understand, reasoned and known how to

## Preface

I in the near past, comes to the new layer of the instant messaging (IM), besides of two (IM) I have known in previous stage of my life named WhatsApp and LINE, the new IM is Telegram. For the record, I used Telegram in academic and learning manners in early stage of usage for example to catch up with lecturer's matter or sometimes online QnA session with lecturer, more of the time, I find out that technology called bot also available in Telegram with numerous example of bots on the market, then my brain towards the development side and wondering if i can build it by myself, and the answer is yes. Thus the preface ending, this article will show you my thought and steps in learning Telegram Bot and of course learn to build it based on the documentation available.

## What is Bot?

Bot is generally a computer program that can execute human actor's use case scenario, Telegram is an IM application so the human actors on the app do the use case of messaging. The conclusion is the Telegram Bot is a running computer program that can send message to human or fellow bots.

## Bot and human in Telegram differentiated, right?

Telegram as an application differs bots from humans user account, so you cannot be mistaken the bots account as humans account.

## Why using Bot? Is it really essential or urgent?

One of reasons of using bot is automating human's business, that's how we mean in Telegram too. There's some human business that human should not mind do it all along, bots do it instead, you can say something tiring like moderate Telegram group, deleting spam message on your group and so on, that's why bots mean business. With the platform Telegram being free as in freedom, bots can be freely developed too and it opens possibility to unlimited range of bots usage.

I feel I can make the urgencies up from the essence of bot usage above, user-oriented urgencies. But when it comes to developers urgencies aside of the nature of open source Telegram bore in hand, developers must be gained some new experience of doing something by building and they will get perks of new skill while bot usages are increasing by the year and of course new career opportunity.

## We can learn something new then, how to started?

Firstly in this article, I will define the scope of the article so you don't getting confused as article goes by.
- Article use Python as language for bot building
- Steps in the article take place in Linux environment
- Using python-telegram-bot to build the bot, install with 'pip install python-telegram-bot'

After above line, you should know the scope and your expectation here, thus we can start the how, very first of the how is enroll your bot to [@BotFather][@BotFather], get the token and you are ready to build your own bot.

## Is that it? We want the actual howto!

Okay, so at this point I assume the previous prerequisite is not a problem anymore and we can take actual lesson of the bot, I can put it on numbered list below so you can keep on the line. there is 3 essential entities for the bot and they must form the program so it can work perfectly. The track is like this:
1. Updater
2. Dispatcher
3. Handlers
4. Filters
5. Form the program

So the point number 1 until 3 is technically a class on the python-telegram-bot library and I can take its role for you starting from the beginning.

Updater set to be update catcher of the bot activity, the Updater will ring the bell if the bot said get an update or two from the user, for the bell working properly you need a Dispatcher to read the bell ring. Dispatcher is like real-life dispatch imagine you are in public service field of job (cop for example), you will need a dispatch if you need something based on the newest event on the field, cop need back up, sent to dispatch then dispatch communicate the message to back up personnel. As of example, I can say Updater is cop and Dispatcher is a dispatch, Updater ring the bell for help, dispatch translate the bell so wanted help can be accommodated to Updater. Handlers is a class where the Dispatcher communicates in order to fulfill Updater's requests, Handlers can be called by Dispatcher when the condition met. Handlers will need Filters to sort out the dispatcher call

At this point, I hope you complete your knowledge about point 1 until 3 above and ready to make the program up. With that knowledge you have, you can utilize 3 entities above starting with Updater.

{% highlight python %}
""" You should do this first """
import telegram.ext
""" Declare and define your updater first """
updater = telegra.ext.Updater(YOURTOKEN, use_context=True)
{% endhighlight %}

If written, your updater is ready and do declare the line to the dispatch, Dispatcher can be initialized from Updater class itself by using

{% highlight python %}
""" Declare the dispatch """
dispatch = updater.dispatcher
{% endhighlight %}

Only if the dispatch declared, you can able to do jobs based on event occurred, you can designed your bot to respond on sent message using handler, there's many Handlers available but for the entry level how to, this article only use MessageHandler to carry on. Filters user by Handlers to determine the kind of request sent from dispatch so the Handlers can respond correctly

{% highlight python %}
""" import handler from the library """
from telegram.ext import MessageHandler, Filters
""" make up the handler to respond sent message filtered as text """
dispatch.add_handler(MessageHandler(Filters.text, yes))
""" previously you must define the function called 'yes' like this"""
def yes(update, context):
  update.message.reply_text("yes")
{% endhighlight %}

Your reaching of this line means you are ready to get more exploration on the bot development, for the reference you can use your own bot using above explanation, for example [echobot][https://www.codementor.io/@karandeepbatra/part-1-how-to-create-a-telegram-bot-in-python-in-under-10-minutes-19yfdv4wrq].

## Closure

I think the knowledge of bot building can be very useful, professionally or casually in remembrance of automation usefulness. With the openness of Telegram, build the Telegram bot can be nice starting point for your bot building journey in the same platform or the others, and I think you might going so with the essential this article provided. You reach the end of the word, thank you.

Special Note: Oh my god, three weeks without an update, this week finally it airs. More articles to come, i assure you. (Akhmal R.)

## Article Source
- [https://www.morningbrew.com/emerging-tech/stories/2020/09/16/survey-chatbot-usage-increased-925-2019-2020][https://www.morningbrew.com/emerging-tech/stories/2020/09/16/survey-chatbot-usage-increased-925-2019-2020]
- [https://python-telegram-bot.readthedocs.io/en/stable/][https://python-telegram-bot.readthedocs.io/en/stable/]
- [https://github.com/python-telegram-bot/python-telegram-bot/wiki/Extensions-%E2%80%93-Your-first-Bot][https://github.com/python-telegram-bot/python-telegram-bot/wiki/Extensions-%E2%80%93-Your-first-Bot]
- [https://www.codementor.io/@karandeepbatra/part-1-how-to-create-a-telegram-bot-in-python-in-under-10-minutes-19yfdv4wrq][https://www.codementor.io/@karandeepbatra/part-1-how-to-create-a-telegram-bot-in-python-in-under-10-minutes-19yfdv4wrq]


[https://www.morningbrew.com/emerging-tech/stories/2020/09/16/survey-chatbot-usage-increased-925-2019-2020]: https://www.morningbrew.com/emerging-tech/stories/2020/09/16/survey-chatbot-usage-increased-925-2019-2020
[https://python-telegram-bot.readthedocs.io/en/stable/]: https://python-telegram-bot.readthedocs.io/en/stable/
[https://github.com/python-telegram-bot/python-telegram-bot/wiki/Extensions-%E2%80%93-Your-first-Bot]: https://github.com/python-telegram-bot/python-telegram-bot/wiki/Extensions-%E2%80%93-Your-first-Bot
[https://www.codementor.io/@karandeepbatra/part-1-how-to-create-a-telegram-bot-in-python-in-under-10-minutes-19yfdv4wrq]: https://www.codementor.io/@karandeepbatra/part-1-how-to-create-a-telegram-bot-in-python-in-under-10-minutes-19yfdv4wrq
[@BotFather]: https://telegram.me/botfather
