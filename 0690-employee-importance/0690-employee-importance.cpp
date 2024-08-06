class Solution {
public:
    int dfs(int id, unordered_map<int, Employee*>& empMap, unordered_set<int>& visited) {
        if (visited.count(id)) {
            return 0;
        }
        visited.insert(id);
        int totalImportance = empMap[id]->importance;
        for (int subId : empMap[id]->subordinates) {
            totalImportance += dfs(subId, empMap, visited);
        }
        return totalImportance;
    }

    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> empMap;
        for (auto emp : employees) {
            empMap[emp->id] = emp;
        }

        unordered_set<int> visited;
        return dfs(id, empMap, visited);
    }
};
