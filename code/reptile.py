import requests
from bs4 import BeautifulSoup

def download_file(url, index):
    local_filename = index+"-"+url.split('/')[-1]
    # NOTE the stream=True parameter
    r = requests.get(url, stream=True)
    with open(local_filename, 'wb') as f:
        for chunk in r.iter_content(chunk_size=1024):
            if chunk: # filter out keep-alive new chunks
                f.write(chunk)
                f.flush()
    return local_filename

root_link="https://www.usenix.org/conference/lisa14/conference-program"
r=requests.get(root_link)

if r.status_code==200:
	soup=BeautifulSoup(r.text)
	index=1
	for link in soup.find_all('a'):
		new_link=root_link+link.get('href')
		if new_link.endswith(".pdf"):
			file_path=download_file(new_link,str(index))
			print new_link+ "->" +file_path
			index+=1
	print "all download finished"
else:
	print "link error happened"
