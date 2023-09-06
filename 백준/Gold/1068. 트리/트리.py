n = int(input())
tree_list = list(map(int, input().split()))
delete_node = int(input())
result = 0


def delete_dfs(delete_node, tree_list):
    tree_list[delete_node] = -100
    for i in range(len(tree_list)):
        if delete_node == tree_list[i]:
            delete_dfs(i, tree_list)


delete_dfs(delete_node, tree_list)

for i in range(n):
    if tree_list[i] != -100 and i not in tree_list:
        result += 1

print(result)