# 广度优先搜索算法找到的是俩点之间的最短距离，不包含权重，总段数最少
from collections import deque

graph = {}
graph['you'] = ['alice', 'bob', 'claire']
graph['bob'] = ['anuj', 'peggy']
graph['alice'] = ['peggy']
graph['claire'] = ['thom', 'jonny']
graph['anuj'] = []
graph['peggy'] = []
graph['thom'] = []
graph['jonny'] = []


def search(name):
	# 创建一个队列
	search_queue = deque()

	# 将你的邻居都加入到这个搜索队列中
	search_queue += graph[name]
	searched = []
	while search_queue:
		person = search_queue.popleft()
		if person not in searched:
			if person_is_seller(person):
				print(person + " is a mango seller!")
				return True
			else:
				search_queue += graph[person]
				searched.append(person)
	return False


def person_is_seller(name):
	return name[-1] == 'm'


search('you')
