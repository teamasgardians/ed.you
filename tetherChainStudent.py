import hashlib as hasher
import datetime as date

# Define our block as
class Block:
  	def __init__(self, index, timestamp, data1, data2, data3, previous_hash):
	    self.index = index
	    self.timestamp = timestamp
	    self.data1 = data1
	    self.data2 = data2
	    self.data3 = data3
	    self.previous_hash = previous_hash
	    self.hash = self.hash_block()
  
	def hash_block(self):
	    sha = hasher.sha256()
	    sha.update(str(self.index) + str(self.timestamp) + str(self.data1) + str(self.data2) + str(self.data3) + str(self.previous_hash))
	    return sha.hexdigest()


# Input the block
# Generate genesis block
def create_genesis_block():

	# Manually construct a block with
	# index zero and arbitrary previous hash
	# course_id = raw_input("Enter the course id: ")
	# tutor_id = raw_input("Enter the tutor id: ")
	# student_id = raw_input("Enter the student id: ")

	return Block(0, date.datetime.now(), "course_id", "tutor_id", "Wallet_id", "0")
  
  

# Generate all later blocks in the blockchain
def next_block(last_block):
	this_index = last_block.index + 1
	this_timestamp = date.datetime.now()

	course_id = raw_input("|-> Course id: ")
	tutor_id = raw_input("|-> Tutor id: ")
	student_id = raw_input("|-> Wallet id: ")

	this_data1 = "Course Name " + course_id
	this_data2 = "Tutor Id " + tutor_id
	this_data3 = "Wallet Id " + student_id

	this_hash = last_block.hash
	return Block(this_index, this_timestamp, this_data1, this_data2, this_data3, this_hash)





print("\t_______________________________________________________________________")
print("")
print("\t|  Student Wallet")
print("\t_______________________________________________________________________")

# Create the block
blockchain = [create_genesis_block()]	
previous_block = blockchain[0]

# How many blocks should we add to the chain
# after the genesis block
num_of_blocks_to_add = 20000

# Add blocks to the chain
for i in range(0, num_of_blocks_to_add):
	print("\n")
	print("\t\t\t----------------------")
	print("\t|\t\t|  Course Selection  |")
	print("\t--->\t\t----------------------")
	

	crt_block = input("\nCreate block? [1/0]: ")
	print("")
	if(crt_block==1):
		block_to_add = next_block(previous_block)
		blockchain.append(block_to_add)
		previous_block = block_to_add
		# Tell everyone about it!
		  
		print("____________________________________________________________________________________________")
		print("");
		print "	|-->  Block #{} added to the the chain".format(block_to_add.index)
		print "	|-->  Hash: {}".format(block_to_add.hash)
		print "	|-->  Pre Hash: {}".format(block_to_add.previous_hash)
		print "	|-->  Creation Time: {}".format(block_to_add.timestamp)
		print "	|-->  Course Id: {}".format(block_to_add.data1)
		print "	|-->  Tutor Id: {}".format(block_to_add.data2)
		print	 "	|-->  Wallet Id: {}".format(block_to_add.data3)
		print("____________________________________________________________________________________________")
	else:
		break