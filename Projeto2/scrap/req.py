from bs4 import BeautifulSoup
from requests import get
from pprint import pprint
from random import randint

mainurl = "https://www.matriculaweb.unb.br/"

def main():
    html = get(mainurl + "graduacao/fluxo.aspx?cod=1856").content
    bsobj = BeautifulSoup(html, "lxml")

    disciplinas = {}
    enum = {}

    for table in bsobj.find('div', {'class':'body table-responsive'})\
              .find_all('div', {'class':'table-responsive'}):
        for tr in table.find_all('tr')[2:]:
            a = tr.a
            reqlist = []

            reqs = get(mainurl + a['href']).content
            bsin = BeautifulSoup(reqs, 'lxml')
            for k in bsin.find('table', {'id':'datatable'})\
                         .find_all('td')[5].find_all('strong'):
                kt = k.text.strip()
                if kt in disciplinas:
                    reqlist.append(kt)

            disciplinas[a['href'].split('=')[-1]] = {
                'nome': a.text.strip(),
                'requisitos': [x for x in reqlist if x != ' ']
            }
    for i, k in enumerate(disciplinas.keys()):
        enum[k] = str(i)

    with open('disciplinas.txt', 'w') as fout:
        fout.write(str(len(disciplinas.keys())) + '\n')
        for dsc in disciplinas:
            for req in disciplinas[dsc]['requisitos']:
                fout.write(enum[dsc] + ' ' + enum[req] +
                           ' ' + str(randint(1,3)) + '\n')

    pprint(disciplinas)

if __name__ == '__main__':
    main()
