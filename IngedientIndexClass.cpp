class IngredientIndexes {
public:
	vector<string> ingredients;
	vector<string> indexes;
	vector<vector<string>> df;

	void setIngredients(vector<vector<string>> data) {
		for (const auto& row : data) {
			this->ingredients.push_back(row[0]);
		}
	}
	void setIndexes(vector<vector<string>> data) {
		for (const auto& row : data) {
			this->indexes.push_back(row[1]);
		}
	}
};
