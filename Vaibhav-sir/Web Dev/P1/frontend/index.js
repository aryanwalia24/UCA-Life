// window.alert("Bruh");
// function init() {
//     document.getElementById("jsworld").innerHTML = "Bruhhhhhhh";
// }
// init();

// var arr = [1,2,3,4,5];
// var newarr = arr.map((e)=>{return e*2});

function renderProductList () {
  // database
  var product = [] // let does'nt get hoisted (i.e refrence error)
  function getProductList () {
    console.log('Fetching product list')
    product = productfromServer;
    initTable()
  }

  // const productList = [
  //   { name: "A", desc: "addi", price: 100 },
  //   { name: "B", desc: "addi", price: 200 },
  //   { name: "C", desc: "addi", price: 300 }
  // ];

  // Loader
  function getLoader () {
    return `<tr><td colspan=4><div class="loader"></div></td></tr>`
  }
  // React part
  function initTable () {
    console.log('Intializing the products html Table')
    if (product?.length === 0) {
      document.getElementById('productMenu').innerHTML = `${getLoader()}`
      return;
    }
    document.getElementById('productMenu').innerHTML = `
    <table>
        <thead>
            <tr>
                <th>Sr No.</th>
                <th>Name</th>
                <th>Desc</th>
                <th>Price</th>
            </tr>
        </thead>
        <tbody>
          ${getProduct()}
        </tbody>
    </table>
    `
  }

  const getProduct = () => {
    // if (product?.length === 0) {
    //   return `<tr><td colspan=4><div class="loader"></div></td></tr>`;
    // }
    var rows = product.map((e, index) => {
      return `<tr>
        <td>${index + 1}</td>
        <td>${e.name}</td>
        <td>${e.desc}</td>
        <td>${e.price}</td>
      </tr>`
    })
    return rows.join('')

    // var rows = ""
    // for (let i = 0; i < productList.length; i++) {
    //   rows = rows +
    //   `<tr>
    //        <td>${i+1}</td>
    //        <td>${productList[i].name}</td>
    //        <td>${productList[i].desc}</td>
    //        <td>${productList[i].price}</td>
    //    </tr>
    //   `;
    // }
    // return rows;
  }

  initTable()
  setTimeout(getProductList, 1000)
  // getProductList();
}

renderProductList()
