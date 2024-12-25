package com.example.login_listview;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import java.util.List;

public class svadapter extends ArrayAdapter<SinhVien> {
    private Context context;
    private int resource;
    private List<SinhVien> listSV;

    // Generate 1 Constructor thu 2 tu duoi len va select none

    public svadapter(Context context, int resource,List<SinhVien> objects) {
        super(context, resource, objects);
        this.context=context;
        this.resource=resource;
        this.listSV=objects;
    }
    // Khai bao 1 class viewholder chua cac thanh phan trong item_list
    class ViewHolder{
        private TextView tvmasv,tvhoten,tvlop;
    }
    //thiet lap hien thi item sv tren listview


    @Override
    public View getView(int position,View convertView,ViewGroup parent) {
        ViewHolder viewHolder;
        // Kiem tra xem converView co rong ko (NULL)
        if (convertView==null){
            convertView= LayoutInflater.from(context).inflate(R.layout.item_list,parent,false);
            //Khai bao khoi tao doi tuong ViewHolder
            viewHolder = new ViewHolder();
            // anh xa (linking)
            viewHolder.tvmasv=convertView.findViewById(R.id.tv_masv);
            viewHolder.tvhoten=convertView.findViewById(R.id.tv_hoten);
            viewHolder.tvlop=convertView.findViewById(R.id.tv_lop);
            convertView.setTag(viewHolder);
        } else {
            viewHolder=(ViewHolder) convertView.getTag();
        }
        //thiet lap gia tri
        SinhVien sv = listSV.get(position);
        viewHolder.tvmasv.setText(sv.getMasv());
        viewHolder.tvhoten.setText(sv.getHoten());
        viewHolder.tvlop.setText(sv.getLop());
        return convertView;
    }
}
