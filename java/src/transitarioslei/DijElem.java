package transitarioslei;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author André
 */
public class DijElem {
    
    public static final int _VIS_WHITE = -1;
    public static final int _VIS_GREY = 0;
    public static final int _VIS_BLACK = 1 ;
    
    private String nome;
    private int nrlocalidades;
    private String pai;
    int vis;
    
    public DijElem(){
        this.nome="";
        this.nrlocalidades=-1;
        this.pai="";
        this.vis=_VIS_WHITE;     
    }
    
    public DijElem(String nome, int nrlocalidades, String pai, int vis){
        this.nome=nome;
        this.nrlocalidades=nrlocalidades;
        this.pai=pai;
        this.vis=vis;  
    }
    
    public DijElem(DijElem elem){
        this.nome=elem.get_Nome();
        this.nrlocalidades=elem.get_Nrlocalidades();
        this.pai=elem.get_Pai();
        this.vis=elem.get_Vis();  
    }
    
    public String get_Nome(){
        return this.nome;
    }
    
    public int get_Nrlocalidades(){
        return this.nrlocalidades;
    }
    
    public String get_Pai(){
        return this.pai;
    }
    
    public int get_Vis(){
        return this.vis;
    }
    
    public void set_Nome(String novo){
        this.nome = novo;
    }
    
    public void set_Nrlocalidades(int novo){
        this.nrlocalidades = novo;
    }
    
    public void set_Pai(String novo){
        this.pai = novo;
    }
    
    public void set_Vis(int novo){
        this.vis =  novo;
    }
    
    @Override
    public boolean equals(Object o){
        if (o==this)
            return true;
        
        if((o==null) || (o.getClass() != this.getClass()))
            return false;
        
        DijElem d = (DijElem) o;
        return (this.nome.equals(d.get_Nome()));
    }
    
    @Override
    public DijElem clone(){
        return new DijElem(this);
    }

    @Override
    public String toString(){
        StringBuilder sn = new StringBuilder();
        sn.append("Destino: "+this.nome+"\n");
        sn.append("Localidades: "+this.nrlocalidades+"\n");
        sn.append("Partida: "+this.pai+"\n");  
        return sn.toString();
    }
    
    @Override
    public int hashCode(){
        return this.nome.hashCode();
    }
}
