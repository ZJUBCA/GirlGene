<template>
  <div class="Factory">
    <el-container class="up-box">
      <el-aside>
        <img class="Img" src="../assets/gene.jpg"/>
      </el-aside>
      <el-main>
        <el-row gutter="50px">
          <el-col :span="12" style="text-align: left;">Gene</el-col>
          <el-col :span="12" style="text-align: right;">
            <img class="gene_code" v-bind:src="gene">
          </el-col>
        </el-row>
        <br>
        <el-row gutter="50px">
          <el-col :span="12" style="text-align: left;">ID</el-col>
          <el-col :span="12" style="text-align: right;">#{{geneId}}</el-col>
        </el-row>
        <br/>
        <el-row gutter="50px">
          <el-col :span="12" style="text-align: left;"><el-input v-model="contract" placeholder="Please enter your contract "></el-input></el-col>
          <el-col :span="12" style="text-align: right;"><el-button type="primary">Import</el-button></el-col>
        </el-row>
      </el-main>
    </el-container>
    <el-container class="down-box">
      <el-aside>
        <el-row gutter="50px">
          <el-col :span="12" style="text-align: left;">ID</el-col>
          <el-col :span="12" style="text-align: right;">#{{geneId}}</el-col>
        </el-row>
        <br/>
        <el-row gutter="50px">
          <el-col :span="12" style="text-align: left;">Gene</el-col>
          <el-col :span="12" style="text-align: right;"><img v-bind:src="gene"/></el-col>
        </el-row>
        <br/>
        <el-row gutter="50px">
          <el-col :span="12" style="text-align: left;">Feature</el-col>
        </el-row>
        <br/>
        <el-row>
          <el-col :span="12" :style="{textAlign: left}">Eye</el-col>
          <el-col :span="12" :style="{textAlign: right}">{{eye}}</el-col>
        </el-row>
        <br/>
        <el-row>
          <el-col :span="12" :style="{textAlign: left}">Hair</el-col>
          <el-col :span="12" :style="{textAlign: right}">{{hair}}</el-col>
        </el-row>
        <br/>
        <el-row>
          <el-col :span="12" :style="{textAlign: left}">Mouth</el-col>
          <el-col :span="12" :style="{textAlign: right}">{{mouth}}</el-col>
        </el-row>
      </el-aside>
      <el-main>
        <div class="factory-room">
            <el-row>
              <el-col :span="12" >
                <div>Source</div>
                <img width="40%"  src="../assets/p1.png"/>
              </el-col>
              <el-col :span="12" >
                <div>Source</div>
                <img width="40%" src="../assets/p2.png"/>
              </el-col>
            </el-row>
          <div>Result</div>
          <div style="min-height:100px;border:solid 2px #a0a0a0;padding-top: 10px;">
                <img v-if="submit" width="30%" src="../assets/p3.png"/>
           </div>
        </div>
      </el-main>
    </el-container>
    <div class="submit-btn" v-if="this.$store.state.login">
      <el-col :span="24"><el-button type="primary" style="width:80%;margin-top: 30px;" @click="toSubmit()">Submit</el-button></el-col>
    </div>
  </div>
</template>

<script>
  import ElContainer from "../../node_modules/element-ui/packages/container/src/main.vue";
  import ElAside from "../../node_modules/element-ui/packages/aside/src/main.vue";
  import ElInput from "../../node_modules/element-ui/packages/input/src/input.vue";
  import ElButton from "../../node_modules/element-ui/packages/button/src/button.vue";
  import ElRow from "element-ui/packages/row/src/row";
  import ElCol from "element-ui/packages/col/src/col";
  import axios from 'axios'

  export default {
    components: {
      ElCol,
      ElRow,
      ElButton,
      ElInput,
      ElAside,
      ElContainer},
    name: 'Card',
    data(){
      return {
        name:"Sakura",
        geneId:"f3673792a676c",
        owner:"girlmakegene",
        gene:require("../assets/code.jpg"),
        eye:"#666",
        hair:"#666",
        mouth:"#666",
        father:"f3673792a389a",
        mother:"7d643a92a676c",
        contract:"",
        submit:false
      }
    },
    created(){
      console.log(this.$route.query.id);
    },
    methods:{
      toSubmit(){
        this.submit=true
      }
    }
  }
</script>

<style scoped>
  .Factory{
    width:80%;
    margin:0 auto;
  }

  .Img{
    width:50%;
    margin:0 auto;
  }

  .up-box{
    font-size: large;
    border-radius: 10px;
    background-color: #545c64;
    color: white;
    padding:20px 30px;
  }

  .down-box{
    font-size: large;
    border-radius: 10px;
    background-color: #545c64;
    color: white;
    padding:20px 30px;
    margin-top:50px;
  }

</style>
