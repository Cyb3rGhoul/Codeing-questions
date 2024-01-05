sort(arr, arr + n);
unordered_set<int> seen;
vector<int> duplicates;

for (int i = 1; i < n; i++)
{
    if (arr[i - 1] == arr[i] && seen.find(arr[i]) == seen.end())
    {
        duplicates.push_back(arr[i]);
        seen.insert(arr[i]);
    }
}

return duplicates.empty() ? vector<int>{-1} : duplicates;
}