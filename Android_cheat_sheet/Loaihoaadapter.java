package com.example.qlhoa;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import java.util.ArrayList;

public class Loaihoaadapter extends BaseAdapter {

    Context mycontext;
    int mylayout;
    ArrayList<Loaihoa> mangloaihoa;

    public Loaihoaadapter(Context mycontext, int mylayout, ArrayList<Loaihoa> mangloaihoa) {
        this.mycontext = mycontext;
        this.mylayout = mylayout;
        this.mangloaihoa = mangloaihoa;
    }

    @Override
    public int getCount() {
        return mangloaihoa.size();
    }

    @Override
    public Object getItem(int i) {
        return null;
    }

    @Override
    public long getItemId(int i) {
        return 0;
    }

    private class ViewHolder {
        TextView txttvTenloaiHoa;
    }

    @Override
    public View getView(int i, View convertview, ViewGroup viewGroup) {
        ViewHolder viewHolder;
        if (convertview == null) {
            viewHolder = new ViewHolder();
            LayoutInflater inflater = (LayoutInflater) mycontext.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            convertview = inflater.inflate(mylayout, null);
            viewHolder.txttvTenloaiHoa = (TextView) convertview.findViewById(R.id.txt);
            convertview.setTag(viewHolder);
        } else {
            viewHolder = (ViewHolder) convertview.getTag();
        }
        Loaihoa loaihoa = mangloaihoa.get(i);
        viewHolder.txttvTenloaiHoa.setText(loaihoa.getTenloaihoa());
        return convertview;
    }

}
