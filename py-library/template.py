# 入力
from sys import stdin
input = stdin.readline

s = input() # sはstr型
n = int(input()) # nはint型

a,b,c = input().split() #3個の文字列の入力を受け取る

str_list = list(input().split()) # n個の文字列がリストに格納される

a,b,c = map(int, input().split()) #3個の数字の入力を受け取る

num_list = list(map(int, input().split())) #n個の数字がリストに格納される

#出力
print(a) #文字列または数字を改行付き

[print(a[i]) for i in range(n)] #リストaを1要素ごとに改行して出力

print(*a) #リストaを空白区切りで出力

