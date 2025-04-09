import requests

print("Zadej název souboru:")
fileName=input()
i=0

with open(fileName, "r") as file:
    for line in file:
        print(i)
        i=i+1
	
	#You need to insert API key
        response = requests.get("https://api.ip2location.io/?key=insertApiKeyHere&ip="+line)
        if("proxy_type\":\"RES\"" in response.text):
            with open("res_"+fileName, "a") as outFile:
                outFile.write(line)
        elif("proxy_type\":\"PUB\"" in response.text):
            with open("pub_"+fileName, "a") as outFile:
                outFile.write(line)
