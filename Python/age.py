def eingeben():
    name= input("Geben Sie Ihren Namen ein: ")
    age = int(input("Geben Sie Ihr Alter ein: "))
    
    year = 2019 + (100-age)
    print("Hallo", name, ",\ndu wirst im Jahr", year, "100 Jahre sein.")

eingeben()
