import feedparser
import urllib.parse
import requests
import json
import sys


def lookup(geo):
    """Look up articles for geo"""



    # Get feed from Google
    feed = requests.get("https://yobit.net/api/3/ticker/"+geo+"-nmc_btc")
    print(feed)
    if feed.status_code != 200:
        sys.exit(1)

    a=json.loads(feed.content)
    b=[a[geo]['buy'], a[geo]['sell']]

    print(b)
    return b


def multi(curr, coin):
    x = 1
    #coins = "https://yobit.net/api/3/ticker/"
    coins = ''
    for i in curr:

        if x == 1:
            coins += i
            coins += coin
            x = 0
        else:
            coins += '-'
            coins += i
            coins += coin

    #feed = requests.get(coins)
    return coins


def requestss(req,a):
    if a == 1:
        feed = requests.get("https://yobit.net/api/3/ticker/" + req)
    elif a == 2:
        feed = requests.get("https://yobit.net/api/3/depth/" + req,params={'limit' : '1'})

    return json.loads(feed.content)

def main():

    coin = [['ltc', 'nmc', 'ppc', 'dash', 'doge', 'cam', 'cann', 'uro', 'via', 'sdc', 'start', 'gsx', 'vtc', 'smbr', 'etco', 'xqn', 'gml',
            'xpy', 'dgms', 'noo', 'nav', 'nkt', 'eags', 'dgd','sys', 'tes', 'sbit', 'pnd','xsp', 'xpc', 'zeit', 'moto','ok', 'spr', 'find', 'nka',
            'ccb', 'con', 'gp', 'blu', 'ozc', 'stk', '2015', 'am', 'xbs', 'vpn', 'decr', 'obs', 'rice', 'bsty','gig', 'oma', 'icn', 'dgore',
            'kobo', 'ybc', 'ktk' ],
            ['nvc', 'sic', 'xvg', 'lts', 'pen', 'crime', 'btcr', 'boom', 'gsm', 'pty', 'voya', 'bitb', 'xco', 'pay', 'bitz', 'twist',
            'stp', 'mtlmc3', 'slfi', 'nxe', 'xau', 'pxl', 'aecc','btcry', 'planet', 'fire', 'anal','ldoge', 'tec', 'zirk', 'xdb','tab', 'ndoge', 'crave',
            'icash','256', 'gift', 'bbcc', 'urc', 'trick', 'u', 'cc', 'metal', 'clam', 'karma', 'cry', 'mrp', 'tcx', 'note', 'rdd','cyp', 'giz', 'xpro',
            'tron','etrust', 'fonz', 'egg' ],
            ['lea', 'hzt', 'p7c', '8bit', 'tp1', 'cf', 'ctk', 'ntrn', 'cov', 'lux', 'drz', '007', 'gram', 'sigu', 'qtz', 'dox', 'xnx',
            'xms', 'gum', 'tdfb', 'bub', 'unit', 'grav', 'epy','goat', 'pnc', 'utle', 'isl','pkb', 'vtn', 'fsn', 'mcar','shell', 'bit16', 'tb', 'm1',
            'krak', 'ba', 'ast', 'mrb', 'bta', 'esc', 'pta', 'dcc', 'arb', 'twerk', 'eqm', 'nice', 'db', 'tng', 'cs','skb', 'genius', 'sed', 'pre',
            '32bit', 'fade', 'snrg' ],
            ['vcoin', 'moin', 'greed', 'exb', 'option', 'gluck', 'dra', 'seeds', 'nanas', 'bnbx', 'arpa', 'vapor', 'dub', 'fist', 'eoc', 'xce',
            'drkt', 'transf', 'ilm', 'gen', 'fury', 'sen', 'nodx','hedg', 'smsr', 'bod', 'gtfo','tennet', 'kc', 'blus', 'xra','ext', 'spx', 'gmcx', 'vtx',
            'poly', 'hxx', 'spktr', 'gene', 'crps', 'bam', 'spec', 'ea', 'tagr', 'haze', 'nuke', '2bacco', 'cyc', 'err','sandg', 'noc', 'shrm', 'asn',
             'grexit', 'mdt', 'nebu' ]]#,
            # ['', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '',
            # '', '', '', '', '', '', '','', '', '', '','', '', '', '','', '', '', '',
            # '', '', '', '', '', '', '', '', '', '', '', '', '', '', '','', '', '', '',
            # '', '', '' ],
            # ['', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '',
            # '', '', '', '', '', '', '','', '', '', '','', '', '', '','', '', '', '',
            # '', '', '', '', '', '', '', '', '', '', '', '', '', '', '','', '', '', '',
            # '', '', '' ],
            # ['', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '',
            # '', '', '', '', '', '', '','', '', '', '','', '', '', '','', '', '', '',
            # '', '', '', '', '', '', '', '', '', '', '', '', '', '', '','', '', '', '',
            # '', '', '' ],
            # ['', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '',
            # '', '', '', '', '', '', '','', '', '', '','', '', '', '','', '', '', '',
            # '', '', '', '', '', '', '', '', '', '', '', '', '', '', '','', '', '', '',
            # '', '', '' ],
            # ['', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '', '',
            # '', '', '', '', '', '', '','', '', '', '','', '', '', '','', '', '', '',
            # '', '', '', '', '', '', '', '', '', '', '', '', '', '', '','', '', '', '',
            # '', '', '' ]]


    btcp=(min(lookup('btc_usd')[0], lookup('btc_usd')[1])) + 35
    temp = []
    for j in range(len(coin)):
        usdString = multi(coin[j], '_usd')
        btcString = multi(coin[j], '_btc')

        usd = requestss(usdString,1)
        btc = requestss(btcString,1)

        allCoinsInUsd = []
        allCoinsInBtc = []
        for i in usd:
            allCoinsInUsd.append((i, max(usd[i]['buy'], usd[i]['sell'])))
            #print(i['buy'])

        for i in btc:
            allCoinsInBtc.append((i, min(btc[i]['buy'], btc[i]['sell'])))

        for i in range(len(allCoinsInBtc)):

            usdPrice = allCoinsInUsd[i][1]# * 1.001
            btcPrice = allCoinsInBtc[i][1]# * 0.999
            #print(usdPrice, btcPrice)
            res = usdPrice/btcp
            if(btcPrice - res) > 0.00000001 and (btcPrice - res) < 0.005:
                temp.append((allCoinsInUsd[i] , btcPrice - res, allCoinsInBtc[i]))

    temp.sort()
    print(temp)


    #bids = requestss(usdString,2)

    # for i in bids:
    #     if i == temp[0][0][0]:
    #         print("hey")


if __name__ == "__main__":
    main()