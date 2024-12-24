import os
import csv
def get_files_and_save_to_csv(directory, output_csv):
    # ファイル情報を保持するリスト
    file_data = []
    
    # 再帰的にディレクトリを探索
    for root, _, files in os.walk(directory):
        for file in files:
            # フルパスでのファイルパスを作成
            file_name = os.path.splitext(file)[0]
            file_data.append(file_name)
    
    # CSV形式で保存
    with open(output_csv, mode='w', newline='', encoding='utf-8') as csv_file:
        writer = csv.writer(csv_file)
        # ヘッダーを書き込む
        writer.writerow(['ID', 'File Path'])
        # ファイルデータを書き込む
        for idx, file_path in enumerate(file_data, start=1):
            writer.writerow([idx, file_path])

def createItemLuaCSV():
    directory_to_scan = r"Source\Lua\Item"
    output_csv_path = r"Document\Data\output.csv"
    get_files_and_save_to_csv(directory_to_scan, output_csv_path)


