class bst:
    def __init__(self,key):
        self.key=key
        self.lch=None
        self.rch=None

    def insert(self,data):
        if self.key is None:
            self.key=data
            return
        if self.key > data:
            if self.lch:
                self.lch.insert(data)
            else:
                self.lch=bst(data)
        else:
            if self.rch:
                self.rch.insert(data)
            else:
                self.rch=bst(data)


root=bst(10)
root.insert(11)
print(root)

