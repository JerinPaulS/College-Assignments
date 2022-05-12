class Node:
    def __init__(self, num):
        self.val = num
        self.right = None
        self.left = None
        
class BT:
	def __init__(self):
		self.root = None
		
	def insertNode(self, num):
		newNode = Node(num)
		if self.root is None:
		    self.root = newNode
		else:
		    curr = self.root
		    flag = 0
		    while flag == 0:
		        choice = int(input("Left (0) or right (1) of " + str(curr.val) + "? "))
		        if choice == 0:
		            if curr.left is None:
		                curr.left = newNode
		                flag = 1
		            else:
		                curr = curr.left
		        else:
		            if curr.right is None:
		                curr.right = newNode
		                flag = 1
		            else:
		                curr = curr.right
		self.inorder(self.root)
		return

	def inorder(self, node):
		if node is None:
		    return
		self.inorder(node.left)
		print(node.val)
		self.inorder(node.right)
		
	def inorder_nr(self, root):
		if root is None:
			return
		stack = []
		curr = root
		while True:
			if curr is not None:
				stack.append(curr)
				curr = curr.left
			elif len(stack) > 0:
				curr = stack.pop()
				print(str(curr.val) + " ")
				curr = curr.right	 
			else:
				break
				
	def preorder_nr(self, root):
		if root is None:
			return
		stack = []
		stack.append(root)
		while len(stack) > 0:
			curr = stack.pop()
			print(curr.val)
			if curr.right is not None:
				stack.append(curr.right)
			if curr.left is not None:
				stack.append(curr.left)
		return
		
	def postorder_nr(self, root):
		if root is None:
			return
		stack1, stack2 = [], []
		stack1.append(root)
		while len(stack1) > 0:
			curr = stack1.pop()
			stack2.append(curr)
			if curr.left is not None:
				stack1.append(curr.left)
			if curr.right is not None:
				stack1.append(curr.right)
		while len(stack2) > 0:
			print(stack2.pop().val)		
			
        
obj = BT()
root = Node(100)
root.left = Node(90)
root.right = Node(200)
root.left.left = Node(80)
root.left.right = Node(96)
root.left.right.right = Node(97)
root.left.right.left = Node(95)
root.left.right.left.left = Node(92)
root.left.right.left.left.right = Node(93)
print("Inorder")
obj.inorder_nr(root)
print("Preorder")
obj.preorder_nr(root)
print("Postorder")
obj.postorder_nr(root)
'''
choice = 1
while choice == 1:
    num = int(input("Enter the number: "))
    obj.insertNode(num)
    choice = int(input("Want to continue: "))
'''
