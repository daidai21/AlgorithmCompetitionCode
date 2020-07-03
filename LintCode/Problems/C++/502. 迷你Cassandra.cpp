/**
 * Definition of Column:
 * class Column {
 * public:
 *     int key;
 *     String value;
 *     Column(int key, string value) {
 *         this->key = key;
 *         this->value = value;
 *    }
 * }
 */


class MiniCassandra {
public:
    MiniCassandra() {
        // do intialization if necessary
    }

    /*
     * @param row_key: a string
     * @param column_key: An integer
     * @param value: a string
     * @return: nothing
     */
    void insert(string &row_key, int column_key, string &value) {
        // write your code here
        this->dic[row_key][column_key] = value;
    }

    /*
     * @param raw_key: a string
     * @param column_start: An integer
     * @param column_end: An integer
     * @return: a list of Columns
     */
    vector<Column> query(string &row_key, int column_start, int column_end) {
        // write your code here
        std::vector<Column> result;
        std::map<int, std::string>& tmp = this->dic[row_key];
        for (auto i = tmp.begin(); i != tmp.end(); ++i) {
            if (i->first >= column_start && i->first <= column_end) {
                result.push_back(Column(i->first, i->second));
            }
        }
        return result;
    }

private:
    std::map<std::string, std::map<int, std::string>> dic; // map is sorted map
};
