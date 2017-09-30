from bs4 import BeautifulSoup
from requests import get
from pprint import pprint

mainurl = "https://www.matriculaweb.unb.br/"

def main():
    html = get(mainurl + "graduacao/fluxo.aspx?cod=1856").content
    bsobj = BeautifulSoup(html, "lxml")

    disciplinas = {}

    for table in bsobj.find("div", {"class":"body table-responsive"})\
              .find_all("div", {"class":"table-responsive"}):
        for tr in table.find_all("tr")[2:]:
            a = tr.a
            reqlist = []

            reqs = get(mainurl + a["href"]).content
            bsin = BeautifulSoup(reqs, "lxml")
            for k in bsin.find("table", {"id":"datatable"})\
                         .find_all("td")[5].find_all('strong'):
                kt = k.text.strip()
                if kt in disciplinas:
                    reqlist.append(kt)

            disciplinas[a["href"].split('=')[-1]] = {
                'nome': a.text.strip(),
                'requisitos': [x for x in reqlist if x != ' ']
            }


    pprint(disciplinas)

if __name__ == '__main__':
    main()
